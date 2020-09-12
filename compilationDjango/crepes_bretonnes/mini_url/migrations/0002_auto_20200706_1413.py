# Generated by Django 3.2 on 2020-07-06 14:13

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('mini_url', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='miniurl',
            name='date',
            field=models.DateTimeField(auto_now_add=True, verbose_name="Date d'enregistrement"),
            preserve_default=False,
        ),
        migrations.AlterField(
            model_name='miniurl',
            name='code',
            field=models.CharField(max_length=6, unique=True),
        ),
    ]
